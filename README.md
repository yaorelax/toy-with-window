# toy-with-window
Toy with the windows on Windows as you can. (hide window / reveal window / kill window)
## Start
- Compile `toydow.cpp`
- CMD : `toydow [hid|vis|del] [@|WindowTitle]`
- `hid` : Hide the WINDOW
- `vis` : Reveal the WINDOW
- `del` : Destory the main process which calls the WINDOW by pid
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
## Copyright and License
Code and documentation copyright 2022 Yaorelax. Code released under [MIT License](https://github.com/yaorelax/toy-with-window/blob/main/LICENSE)
