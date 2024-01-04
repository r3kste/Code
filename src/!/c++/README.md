Formatter: astyle <br>
`
astyle "*.cpp" -p -f -xj -xg -xe -xd --style=attach --recursive -n
`

Runner: g++ <br>
`
g++ -O2 -Wall -g "${file}" -o "${fileDirname}/.${fileBasenameNoExtension}.out"
`
