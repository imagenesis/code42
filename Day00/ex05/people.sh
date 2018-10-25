#!/bin/sh
ldapsearch -LLL -Q  "(uid=z*)" | grep "^cn: *" | cut -c5- | sort -r
