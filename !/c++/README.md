Formatter: astyle <br>
`
astyle "*.cpp" -p -jfq -xg -xe -xb -xd --style=break --recursive -n
`

Runner: g++ <br>
`
g++ "$fileName" -o ".$fileNameWithoutExt" && ./.$fileNameWithoutExt.out
`
