//
//  MacroHeader.h
//  MacroGather
//
//  Created by chuangLan on 2021/8/11.
//

#ifndef MacroHeader_h
#define MacroHeader_h


#define BYLog(format, ...) printf("class: < %s:(%d行) > method: %s \n%s\n", [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __PRETTY_FUNCTION__, [[NSString stringWithFormat:(format), ##__VA_ARGS__] UTF8String] )


#pragma mark------------------设备判断--------------

//ipad
#define isPad ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)

//iphone5
#define by_Dev_iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)

//iphone6p
#define by_Dev_iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)

//iphone6p
#define by_Dev_iPhone6Plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

//iphoneX
#define by_Dev_iPhoneX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)

//判断iPHoneXr
#define by_Dev_iPhoneXr ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)
//判断iPhoneXs
#define by_Dev_iPhoneXs ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)

 //判断iPhoneXs Max
#define by_Dev_iPhoneXs_Max ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) && !isPad : NO)

#define IPHONE_X_Series \
({BOOL isPhoneX = NO;\
if (@available(iOS 11.0, *)) {\
isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
}\
(isPhoneX);})



#pragma mark------------------颜色--------------

//颜色
#define by_RGBA_Color(r,g,b,a) ([UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a])

#define by_RGB_Color(r,g,b) ([UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1])

//随机颜色
#define by_RGB_RandomColor ([UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1])

//hex颜色
#define by_RGB_HexColor(hexValue) ([UIColor colorWithRed:((float)((hexValue & 0xFF0000) >> 16)) / 255.0 green:((float)((hexValue & 0xFF00) >> 8)) / 255.0 blue:((float)(hexValue & 0xFF)) / 255.0 alpha:1.0])


#pragma mark------------------系统单例缩写--------------
//APP对象 （单例对象）
#define KKApplication [UIApplication sharedApplication]
//主窗口 （keyWindow）
#define kKeyWindow [UIApplication sharedApplication].keyWindow
//APP对象的delegate
#define KKAppDelegate [UIApplication sharedApplication].delegate
//NSUserDefaults实例化
#define KKUserDefaults [NSUserDefaults standardUserDefaults]
//通知中心 （单例对象）
#define KKNotificationCenter [NSNotificationCenter defaultCenter]


#pragma mark------------------屏幕尺寸--------------
#define KKStatusBarHeight ([[UIApplication sharedApplication] statusBarFrame].size.height)

#define KKNaviGationHeight ([[UIApplication sharedApplication] statusBarFrame].size.height +44)

#define KKTabBarHeight (KKBottomAreaHeight +49)

#define KKBottomAreaHeight (IPHONE_X_Series ? 34:0)


#define SCREEN_WIDTH_TO375_RATIO (KKBoundsWidth / 375)
#define SCREEN_HEIGHT_TO667_RATIO (KKBoundsHeight / 667)
#define SCREEN_WIDTH_TO320_RATIO (KKBoundsWidth / 320)
#define SCREEN_HEIGHT_TO812_RATIO (KKBoundsHeight / 812.0)
#define SCREEN_WIDTH_TO750_RATIO (KKBoundsWidth / 750)

//屏宽
#define KKBoundsWidth \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.width)
//屏高
#define KKBoundsHeight \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.height)
//屏的size(宽、高)
#define KKBoundsScreenSize \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale) : [UIScreen mainScreen].bounds.size)



#pragma mark------------------空 判断--------------
//字符串是否为空
#define by_StringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || [str isEqual:[NSNull null]] ||str == nil || [str isEqualToString:@"<null>"]|| [str isEqualToString:@"(null)"]|| [str length] < 1 ? YES : NO )
//数组是否为空
#define by_ArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
//字典是否为空
#define by_DictIsEmpty(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys.count == 0)
//对象是否为空
#define by_ObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))

#define by_NullToString(str) (by_StringIsEmpty(str)? @"":str)
#define by_NullTo0String(str) (by_StringIsEmpty(str)? @"0":str)



#pragma mark------------------主线程执行--------------
#define excecuteOnMain(a) if ([NSThread isMainThread]) {\
a\
}\
else {\
dispatch_async(dispatch_get_main_queue(), ^{\
a\
});\
}


#pragma mark - encode and initCoderRuntime

#define encodeRuntime(A) \
\
unsigned int count = 0;\
Ivar *ivars = class_copyIvarList([A class], &count);\
for (int i = 0; i<count; i++) {\
Ivar ivar = ivars[i];\
const char *name = ivar_getName(ivar);\
NSString *key = [NSString stringWithUTF8String:name];\
id value = [self valueForKey:key];\
[encoder encodeObject:value forKey:key];\
}\
free(ivars);\
\

#define initCoderRuntime(A) \
\
if (self = [super init]) {\
unsigned int count = 0;\
Ivar *ivars = class_copyIvarList([A class], &count);\
for (int i = 0; i<count; i++) {\
Ivar ivar = ivars[i];\
const char *name = ivar_getName(ivar);\
NSString *key = [NSString stringWithUTF8String:name];\
id value = [decoder decodeObjectForKey:key];\
[self setValue:value forKey:key];\
}\
free(ivars);\
}\
return self;\
\


#pragma mark------------------空语句挂载断点--------------

#ifdef DEBUG
#define __NOP__ assert(1)
#else
#define __NOP__
#endif


#pragma mark------------------角度转换弧度 由弧度转换角度--------------
#define by_DegreesToRadian(x) (M_PI * (x) / 180.0)
#define by_RadianToDegrees(radian) (radian*180.0)/(M_PI)


#pragma mark------------------强弱引用--------------
#ifndef weakify
#if DEBUG
#if __has_feature(objc_arc)
#define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
#endif
#else
#if __has_feature(objc_arc)
#define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
#endif
#endif
#endif

#ifndef strongify
#if DEBUG
#if __has_feature(objc_arc)
#define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
#endif
#else
#if __has_feature(objc_arc)
#define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
#endif
#endif
#endif

#endif /* MacroHeader_h */
