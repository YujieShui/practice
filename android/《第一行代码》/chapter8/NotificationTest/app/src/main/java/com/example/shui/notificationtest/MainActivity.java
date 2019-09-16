package com.example.shui.notificationtest;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Intent;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.net.Uri;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.app.NotificationCompat;
import android.view.View;
import android.widget.Button;

import java.io.File;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button sendNotifyButton = (Button) findViewById(R.id.send_notify);
        sendNotifyButton.setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        switch (view.getId()) {
            case R.id.send_notify:
                // 利用 PendingIntent 使通知跳转
                Intent intent = new Intent(this,NotificationActivity.class);
                PendingIntent pi = PendingIntent.getActivity(this,0,intent,0);
                // 初始化通知内容
                NotificationManager manager = (NotificationManager) getSystemService(NOTIFICATION_SERVICE);
                Notification notification = new NotificationCompat.Builder(this)
                        .setContentText("这是标题")
                        .setContentText("这是正文，这是正文")
                        .setWhen(System.currentTimeMillis())
                        .setSmallIcon(R.mipmap.ic_launcher)
                        .setLargeIcon(BitmapFactory.decodeResource(getResources(), R.mipmap.ic_launcher))
                        .setContentIntent(pi)// 设置通知点击跳转
                        .setSound(Uri.fromFile(new File("/system/media/audio/ringtones/Luna.ogg")))// 设置通知铃声
                        .setAutoCancel(true)// 设置通知点击之后是否消失
                        .setVibrate(new long[] {0,1000,1000,1000})// 设置震动，注意声明整栋的权限 震动一秒，静止一秒，再震动一秒
                        .setLights(Color.GREEN,1000,1000)// LED 灯光闪烁
//                        .setDefaults(NotificationCompat.DEFAULT_ALL)// 默认通知效果
                        .build();
                manager.notify(1, notification);
                break;
            default:
                break;
        }
    }
}
