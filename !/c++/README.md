Formatter: astyle <br>
`
astyle "*.cpp" -p -jfq -xg -xe -xb -xd --style=break --recursive -n
`

Runner: g++ <br>
`
g++ -O2 -Wall -g "${file}" -o "${fileDirname}/.${fileBasenameNoExtension}.out"
`
