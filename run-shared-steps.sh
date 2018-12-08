#!/bin/sh

. steps/create-object-files

. steps/create-shared-library

. steps/link-dynamically

. steps/use-shared-library-LD_LIBRARY_PATH

