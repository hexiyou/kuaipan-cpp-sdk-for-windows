金山快盘的c++版SDK,基于Qt编写，vc和qt均可直接调用（仅限于windows平台）.

|
|
|
|



下载源码，进入kpSDK\examples\qtdll目录，使用QtCreator编译qtdll工程文件即可得出对应的kpSDK.dll库和kpSDK.lib；如需要增加更多函数，可在main.cpp文件中自行添加。



测试用例见本文最后，或者到Downloads处下载测试example。

--------------2012.4.4-----------------------
修改kpsdk.h和kpsdk.cpp部分函数入口参数属性，避免多次调用后被修改。


-----------2012.4.1------------------------
提供12个接口。
其中以下接口通过传参返回解析json后的参数值。

kpReqTmpToken		//获取临时token
kpAccessToken		//获取正式token
kpUsrInfo		//获取用户信息
kpUploadLocate		//获取上传服务器节点


以下接口传回json，要自行解析
kpMetaData		//文件(夹)信息
kpCreateFolder		//新建文件夹
kpShareFile		//分享文件
kpDelFile		//删除文件
kpMvFile		//移动文件
kpCpFile		//复制文件
kpUploadFile		//上传文件

下载文件接口kpDownloadFile调用后直接下载，不传json。


---



http://code.google.com/p/kuaipan-cpp-sdk-for-windows/downloads/list


中有已经编译出来的sdk库和测试example程序（这个是最初版，仅提供基本测试）。