#include <jni.h>
#include <string>
#include <stdio.h>      //引入系统的头文件
#include "jni-test.h"  //引入自己定义的头文件 “”


extern "C"
jstring Java_com_example_ndktest_MainActivity_get(JNIEnv *env, jobject thiz){
    callJavaMethod(env,thiz);
    return env->NewStringUTF("hello world from jni");
}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndktest_MainActivity_set(JNIEnv *env, jobject thiz, jstring string) {
    char* str = (char*)env->GetStringUTFChars(string,NULL);
    printf("%s  ",str);
    env->ReleaseStringUTFChars(string,str);
}


void callJavaMethod(JNIEnv *env,jobject thiz){
    jclass clazz = env->FindClass("com/example/ndktest/MainActivity");
    if (clazz == NULL){
        printf("clazz == NULL");
        return;
    }
    jmethodID  id = env->GetStaticMethodID(clazz,"methodCalledByJni","(Ljava/lang/String;)V");//签名规则
    if (id == NULL){
        printf("id == NULL");
        return;
    }
    jstring  msg = env->NewStringUTF("msg send in jni call java");
    env->CallStaticVoidMethod(clazz, id, msg);
}
