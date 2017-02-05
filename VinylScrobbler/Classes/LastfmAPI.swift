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
    
    let baseURL = URL(string: "https://e2d16328.ngrok.io")! // "https://stream-scrobbler.jesseditson.com/"
    
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
    
    func logout() {
        self.jwt = nil
        UserDefaults.standard.setValue(nil, forKey: "VS_JWT")
        self.authenticated = false
    }
    
    func POSTRequest(path: String, body: JSON, onComplete: @escaping ServiceResponse) throws {
        if let u = URL(string: path, relativeTo: baseURL) {
            var request = URLRequest(url: u)
            request.httpMethod = "POST"
            try request.httpBody = body.rawData()
            
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
}
