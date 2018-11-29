#!/bin/sh

#  jenkins.sh
#
#  Created by xiaoming han on 16/4/6.
#  Copyright © 2016年 AutoNavi. All rights reserved.

export LANG=en_US.UTF-8

SRCROOT=$(cd "$(dirname "$0")"; pwd)

cd ${SRCROOT}

pod install --verbose --no-repo-update

./AggregateFMWK.sh -x -t MASCTXPassengerKit
