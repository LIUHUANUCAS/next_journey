#!/bin/bash
templatefile="00-solution-template.cpp"
bname=`basename $0`

if [ $# -lt 1 ];then
    echo "./$bname '1. Two Sum' => 1-Two-Sum.cpp"
    exit 0
fi

function get_filename(){
    echo "$1" |sed 's/\.//g'|sed 's/ /-/g'|xargs -n1 -I{} echo {}.cpp
}

curdir=`dirname $0`
targetdir=$curdir
if [ ! -z "$2" ];then
    echo "dirname $2"
    targetdir="$2"
fi

name=`get_filename "$1" `
echo "filename:${name}"

src="$curdir/$templatefile"
dest="${targetdir}/${name}"

echo "$src => $dest"
cp  "${src}" "${dest}"
