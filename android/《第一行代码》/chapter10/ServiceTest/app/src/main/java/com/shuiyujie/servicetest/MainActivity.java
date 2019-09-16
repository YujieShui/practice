package com.shuiyujie.servicetest;

import android.content.ComponentName;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.IBinder;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import static android.icu.lang.UCharacter.GraphemeClusterBreak.V;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private MyService.DownLoadBinder downLoadBinder;

    private ServiceConnection serviceConnection = new ServiceConnection() {

        @Override
        public void onServiceConnected(ComponentName name, IBinder service) {
            // 通过 ServiceConnection 将 Activity 与 service 绑定
            downLoadBinder = (MyService.DownLoadBinder) service;
            // 绑定之后即可调用 DownLoadBinder 的 public 方法
            downLoadBinder.startDownload();
            downLoadBinder.getProcess();
        }

        @Override
        public void onServiceDisconnected(ComponentName name) {

        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button startButton = (Button) findViewById(R.id.start_service);
        Button stopButton = (Button) findViewById(R.id.stop_service);
        Button bindService = (Button) findViewById(R.id.bind_service);
        Button unBindService = (Button) findViewById(R.id.unbind_service);
        startButton.setOnClickListener(this);
        stopButton.setOnClickListener(this);
        bindService.setOnClickListener(this);
        unBindService.setOnClickListener(this);
    }


    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.start_service:
                // 使用 Intent 对象调用服务
                Intent startIntent = new Intent(this, MyService.class);
                startService(startIntent);
                break;
            case R.id.stop_service:
                Intent stopIntent = new Intent(this, MyService.class);
                stopService(stopIntent);
                break;
            case R.id.bind_service:
                Intent bindIntent = new Intent(this, MyService.class);
                // BIND_AUTO_CREATE:活动和服务进行绑定后自动创建服务
                bindService(bindIntent, serviceConnection, BIND_AUTO_CREATE);
                break;
            case R.id.unbind_service:
                unbindService(serviceConnection);
                break;
            default:
                break;
        }
    }
}
