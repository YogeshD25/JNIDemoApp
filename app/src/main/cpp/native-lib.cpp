#include <jni.h>
#include <string>
#include <android/log.h>

#define  LOG_TAG    "JNIDemo"

#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#define  LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnidemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    LOGI("ABCD");
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_jnidemo_MainActivity_sendYourName(JNIEnv *env, jobject thiz, jstring first_name,
                                                   jstring last_name) {
    // TODO: implement sendYourName()
    char returnString[20];
    const char *fN = env->GetStringUTFChars(first_name, NULL);
    const char *lN = env->GetStringUTFChars(last_name, NULL);

    strcpy(returnString,fN); // copy string one into the result.
    strcat(returnString,lN); // append string two to the result.

    env->ReleaseStringUTFChars(first_name, fN);
    env->ReleaseStringUTFChars(last_name, lN);


    return env->NewStringUTF(returnString);
}extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_example_jnidemo_MainActivity_stringArrayFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement stringArrayFromJNI()
    char *days[]={"Java",
                  "Android",
                  "Django",
                  "SQL",
                  "Swift",
                  "Kotlin",
                  "Springs"};

    jstring str;
    jobjectArray day = 0;
    jsize len = 7;
    int i;

    day = env->NewObjectArray(len,env->FindClass("java/lang/String"),0);

    for(i=0;i<7;i++)
    {
        str = env->NewStringUTF(days[i]);
        env->SetObjectArrayElement(day,i,str);
    }

    return day;
}