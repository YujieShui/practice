package com.shuiyujie.servicebestpractice;

/**
 * Created by shui on 2017/8/8.
 */

public interface DownloadListener {

    void onProgress(int process);// 加载进度

    void onSuccess();// 下载成功提示

    void onFailed();// 下载失败提示

    void onPaused();// 通知暂停下载

    void onCanceled();// 通知取消下载
}
