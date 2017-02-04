//
//  Package.swift
//  VinylScrobbler
//
//  Created by Jesse Ditson on 2/4/17.
//  Copyright © 2017 Jesse Ditson. All rights reserved.
//

import PackageDescription

let package = Package(
    name: "VinylScrobbler",
    targets: [],
    dependencies: [
        .Package(url: "https://github.com/SwiftyJSON/SwiftyJSON.git", versions: Version(1,0,0)..<Version(3, .max, .max)),
        ]
)
