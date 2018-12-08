#!/bin/sh

. steps/create-object-files

. steps/create-static-library

. steps/link-statically

./bin/statically-linked
