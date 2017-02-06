//
//  LastfmAPI.swift
//  VinylScrobbler
//
//  Created by Jesse Ditson on 2/4/17.
//  Copyright © 2017 Jesse Ditson. All rights reserved.
//

import Foundation

typealias ServiceResponse = (JSON, Error?) -> Void

class LastfmAPI: NSObject {
    static let sharedInstance = LastfmAPI()
    
    var jwt: String? = nil
    var authenticated: Bool = false
    
    let baseURL = URL(string: "https://66217380.ngrok.io")! // "https://stream-scrobbler.jesseditson.com/"
    
    override init() {
        super.init()
        self.jwt = UserDefaults.standard.string(forKey: "VS_JWT")
        if self.jwt != nil {
            self.authenticated = true
        }
    }
    
    func login(username: String, password: String, onComplete: @escaping ServiceResponse) throws {
        let body = JSON(["username": username, "password": password])
        try self.POSTRequest(path: "login", body: body) { (response, error) in
            let jwt = response["token"].string
            if jwt != nil && error == nil {
                self.jwt = jwt
                UserDefaults.standard.setValue(jwt, forKey: "VS_JWT")
                self.authenticated = true
            }
            onComplete(JSON.null, error)
        }
    }
    
    func identify(path: String, onComplete: @escaping ServiceResponse) throws {
        let file = [
            "path": path,
            "type": "audio/x-caf",
            "name": "recording.caf"
        ]
        try self.POSTRequest(path: "identify", data: JSON.null, files: [file], onComplete: onComplete)
    }
    
    func logout() {
        self.jwt = nil
        UserDefaults.standard.setValue(nil, forKey: "VS_JWT")
        self.authenticated = false
    }
    
    func POSTRequest(path: String, body: JSON, onComplete: @escaping ServiceResponse) throws {
        try self.POSTRequest(path: path, data: body, files: nil, onComplete: onComplete)
    }
    
    func POSTRequest(path: String, data: JSON, files: [[String:String]]?, onComplete: @escaping ServiceResponse) throws {
        if let u = URL(string: path, relativeTo: baseURL) {
            var request = URLRequest(url: u)
            let boundary = generateBoundaryString()

            request.httpMethod = "POST"
            request.setValue("multipart/form-data; boundary=\(boundary)", forHTTPHeaderField: "Content-Type")
            if let jwt = self.jwt {
                request.setValue("Bearer: \(jwt)", forHTTPHeaderField: "Authorization")
            }

            var body = Data()
            
            body.append("--\(boundary)\r\n".data(using: String.Encoding.utf8)!)
            for (key, value) in data {
                body.append("Content-Disposition:form-data; name=\"\(key)\"\r\n\r\n".data(using: String.Encoding.utf8)!)
                body.append("\(value.string)\r\n".data(using: String.Encoding.utf8)!)
            }
            
            if let arr = files {
                for file in arr {
                    let filename = file["name"]
                    let filePath = file["path"]
                    let type = file["type"]
                    let data = try Data(contentsOf: URL(string: filePath!)!)
                    
                    body.append("--\(boundary)\r\n".data(using: String.Encoding.utf8)!)
                    body.append("Content-Disposition:form-data; name=\"file\"; filename=\"\(filename)\"\r\n".data(using: String.Encoding.utf8)!)
                    body.append("Content-Type: \(type)\r\n\r\n".data(using: String.Encoding.utf8)!)
                    body.append(data)
                    body.append("\r\n".data(using: String.Encoding.utf8)!)
                }
            }
            
            body.append("--\(boundary)--\r\n".data(using: String.Encoding.utf8)!)
            
            let bodyString = String(data: body, encoding: .utf8)
            print("sending \(bodyString)")

            
            request.httpBody = body
            
            let session = URLSession.shared
            
            let task = session.dataTask(with: request, completionHandler: { (data, response, error) in
                if let d = data {
                    let json:JSON = JSON(data: d)
                    DispatchQueue.main.async {
                        onComplete(json, error)
                    }
                } else {
                    onComplete(JSON.null, error)
                }
            })
            
            task.resume()
        }
    }
    
    func generateBoundaryString() -> String {
        return "Boundary-\(NSUUID().uuidString)"
    }
}
