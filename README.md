# toy-with-window
Toy with the windows on Windows as you can. (hide window / reveal window / kill window)
## Start
- Compile `toydow.cpp`
- CMD : `toydow [hid|vis|del][-w|-k] [@|WindowTitle]`
- `hid` : Hide the WINDOW
- `vis` : Reveal the WINDOW
- `del` : Destory the main process which calls the WINDOW by pid
- `[hid|vis|del]-w` : Wait for window and do once
- `[hid|vis|del]-k` : Keep doing
- `@` : Refer to itself
- `WindowTitle` : Fullname of the WINDOW
## Example
To hide console window itself which calls toydow :
```
toydow hid @
```
To destory the window named "toydow - VSCode"
```
toydow del "toydow - VSCode"
```
wait and destory the window named "toydow - VSCode"
```
toydow del-w "toydow - VSCode"
```
keep destorying the window named "toydow - VSCode"
```
toydow del-k "toydow - VSCode"
```
## Copyright and License
Code and documentation copyright 2022 Yaorelax. Code released under [MIT License](https://github.com/yaorelax/toy-with-window/blob/main/LICENSE)
