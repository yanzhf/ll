## Tiny3.0插件改造
### Podfile文件修改：
####如果2.5插件是TE插件更改如下, 如果有其他需要，还需要引入3.0其他平台包
```
  pod 'TinyKern','~>1.0.16-debug'
  pod 'TinyProtocol', '~>1.0.0-debug'
  pod 'TinyJS', '~>1.2.33-BETA'
  pod 'TinyUI','~>1.2.8-BETA'
  pod 'TinyNetwork','~>1.0.22-debug'
```
####如果2.5插件是TP插件更改如下，如果有其他需要，还需要引入3.0其他平台包

```
  pod 'TinyKern','~>1.0.16-debug'
  pod 'TinyProtocol', '~>1.0.0-debug'
```

####遵守协议如下
```
@interface XXXXXX() <TinyPlugsProtocol, TinyModuleProtocol>

```
####必须实现方法如下：两个宏协议方法
####注册类，无需在.json里面进行注册

`TINY_MODULE_AUTO_REGISTER`**(TinyPhotoVideoView)**
####原生于JS使用的class和className，支持统一名称和不统一名称
`TINY_NAME_SERVICE`**(PickView, TinyPhotoVideoView)**
####如果是2.5版本是TE插件使用如下
```
@implementation XXXXXX


+ (TinyPluginType)pluginType
{
    return TinyPluginType_UI;
}
```
####如果是2.5版本是TP插件使用如下
```
@implementation XXXXXX


+ (TinyPluginType)pluginType
{
    return TinyPluginType_TP;
}
```