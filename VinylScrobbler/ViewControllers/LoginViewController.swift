//
//  LoginViewController.swift
//  VinylScrobbler
//
//  Created by Jesse Ditson on 2/4/17.
//  Copyright © 2017 Jesse Ditson. All rights reserved.
//

import Foundation
import UIKit

class LoginViewController: UIViewController {
    
    @IBOutlet weak var usernameInput: UITextField!
    @IBOutlet weak var passwordInput: UITextField!
    @IBOutlet weak var errorLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.loginIfAuthenticated()
    }
    
    func loginIfAuthenticated() {
        if LastfmAPI.sharedInstance.authenticated {
            self.performSegue(withIdentifier: "showLoggedIn", sender: self)
        }
    }
    
    @IBAction func login() {
        if let username = self.usernameInput.text, let password = self.passwordInput.text {
            do {
                try LastfmAPI.sharedInstance.login(username: username, password: password) { (_, error) in
                    if let error = error {
                        self.errorLabel.text = error.localizedDescription
                    }
                    self.loginIfAuthenticated()
                }
            } catch let error {
                self.errorLabel.text = error.localizedDescription
            }
        }
    }

}
