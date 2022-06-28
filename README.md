# toy-with-window
Toy with the windows on Windows as you can.
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
To destory the window called 『toydow - VSCode』
```
toydow del "toydow - VSCode"
```
