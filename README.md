# WonderSenseNative-Parser

このライブラリはWonderSenseから送られてくるByteArrayを実数に変換するために利用される。
 

## Test
### Tool

| | Tool       | Version |
|-|------------|---------|
|1| GoogleTest | 1.10.0  |
|2| CMake      | 3.13.0  |
|3| GNU make   | 4.2.1   |

Requirement.
単体テストはGoogleTestを用いて行なう。
CMake, makeはビルドツール。


### Build
```sh
./run.sh build
```
ビルドの際にテスト結果も表示される。


### Clean
```sh
./run.sh clean
```
このときに、GoogleTestも一緒に消される。
