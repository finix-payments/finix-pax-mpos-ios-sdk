//
//  swift_smartlanding_sdk.h
//  SmartlandingSDK
//
//  Created by 范俊 on 2022/9/2.
//

#ifndef swift_smartlanding_sdk_h
#define swift_smartlanding_sdk_h

#ifdef __cplusplus
extern "C" {
#endif


#define DEV_INFO_KEY_FACTORY "factory"
#define DEV_INFO_KEY_MODEL "model"
#define DEV_INFO_KEY_SERIAL_NO "serial_no"
#define DEV_INFO_KEY_OS_TYPE  "os_type"
#define DEV_INFO_KEY_OS_VERSION  "os_ver"
#define DEV_INFO_KEY_HARDWARE_INFO "hd_info"


int doInstall(int type, const char *filepath, const char *appId);

int doUninstall(int type, const char *appId);

int doRki(const char *ip, int port);

int getDeviceInfo(const char *type, char *out, int out_cap);

typedef struct _APP_INFO {
    char appId[64];
    char name[64];
//    char pkg[128];
    char version[64];
    int installTimeInSecond;
} App_Info;

int getInstalledApp(App_Info out[], int cap);


#ifdef __cplusplus
}
#endif

#endif /* swift_smartlanding_sdk_h */
