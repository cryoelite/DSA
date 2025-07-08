#!/bin/bash

base_url=$1
problem_input_txt_name="input.txt"
problem_output_txt_name="output.txt"
problem_solution_md_name="solution.md"
problem_file_name="sol.cpp"

echo "Setting up a new online problem from $base_url"

echo "Parsing url"
readonly URI_REGEX='^(([^:/?#]+):)?(//((([^:/?#]+)@)?([^:/?#]+)(:([0-9]+))?))?((/|$)([^?#]*))(\?([^#]*))?(#(.*))?$'
#                    ↑↑            ↑  ↑↑↑            ↑         ↑ ↑            ↑↑    ↑        ↑  ↑        ↑ ↑
#                    ||            |  |||            |         | |            ||    |        |  |        | |
#                    |2 scheme     |  ||6 userinfo   7 host    | 9 port       ||    12 rpath |  14 query | 16 fragment
#                    1 scheme:     |  |5 userinfo@             8 :...         ||             13 ?...     15 #...
#                                  |  4 authority                             |11 / or end-of-string
#                                  3  //...                                   10 path

parse_scheme() {
    [[ "$base_url" =~ $URI_REGEX ]] && echo "${BASH_REMATCH[2]}"
}
parse_authority() {
    [[ "$base_url" =~ $URI_REGEX ]] && echo "${BASH_REMATCH[4]}"
}
parse_user() {
    [[ "$base_url" =~ $URI_REGEX ]] && echo "${BASH_REMATCH[6]}"
}
parse_host() {
    [[ "$base_url" =~ $URI_REGEX ]] && echo "${BASH_REMATCH[7]}"
}
parse_port() {
    [[ "$base_url" =~ $URI_REGEX ]] && echo "${BASH_REMATCH[9]}"
}
parse_path() {
    [[ "$base_url" =~ $URI_REGEX ]] && echo "${BASH_REMATCH[10]}"
}
parse_rpath() {
    [[ "$base_url" =~ $URI_REGEX ]] && echo "${BASH_REMATCH[11]}"
}
parse_query() {
    [[ "$base_url" =~ $URI_REGEX ]] && echo "${BASH_REMATCH[13]}"
}
parse_fragment() {
    [[ "$base_url" =~ $URI_REGEX ]] && echo "${BASH_REMATCH[15]}"
}
#From https://stackoverflow.com/a/45977232/13036358 and https://stackoverflow.com/a/63993578/13036358

domain=$(parse_host | rev| cut -d "." -f 2 | rev) #Get domain name, if its an IP like 192.168.1.2 then just 1.2, if its a domain like abc.com then get abc, and if its something like www.x.y.z.com then just get z
problem_name=$(parse_path | rev | cut -d "/" -f 1 | rev) #Reverse the path from abc/xyz to zyx/cba then get zyx and reverse it back to xyz, getting the last item
echo "Normalizing $domain and $problem_name to form a bash-safe directory name"
safe_domain=$(echo "$domain" | iconv --to-code ASCII//TRANSLIT)
safe_problem_name=$(echo "$problem_name" | iconv --to-code ASCII//TRANSLIT)
outdir="./$safe_domain/$safe_problem_name"

#From https://stackoverflow.com/a/19234661/13036358

echo "Creating $outdir"
mkdir -p $outdir

echo "Creating base files in the dir"
touch $outdir/$problem_input_txt_name
touch $outdir/$problem_output_txt_name
touch $outdir/$problem_solution_md_name
printf "//Problem: $base_url" > "$outdir/$problem_file_name"
printf "# $safe_problem_name \n## Input \n## Problem \n## Output \n## Constraints \n## Observations \n## Solution \nTC: O() SC: O() Time taken to solve:  \n## Problem Categories \n## Lessons to remember \n" > "$outdir/$problem_solution_md_name"
 

echo "Finished creating problem directory $outdir and problem file $outdir/$problem_file_name"
