#!/bin/bash
git tag --list | grep -E '^v([0-9]+\.){1,3}[0-9]+$' | sort -V | tail -n 1
