package com.shuiyujie.newworktest.networktest;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    TextView responseText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button sendRequst = (Button) findViewById(R.id.send_request);
        responseText = (TextView) findViewById(R.id.response_text);
        sendRequst.setOnClickListener(this);
    }

    @Override
    public void onClick(View view) {
        if (view.getId() == R.id.send_request) {
            sendRequsetWithHttpURLConnection();
        }
    }

    /**
     * HttpURLConnection 访问网络
     */
    private void sendRequsetWithHttpURLConnection() {
        // 开启线程发起网络请求
        new Thread(new Runnable() {
            @Override
            public void run() {
                HttpURLConnection connection = null;
                BufferedReader reader = null;

                try {
                    // 百度首页无法获取输入流，有人说是大网站设置了反扒手。
                    // 换成小网站可以，通过 okHttp 也可以获取输入流
                    URL url = new URL("http://bbs.csdn.net/topics/390581969");
                    // 获取 HttpURLConnection 实例对象
                    connection = (HttpURLConnection) url.openConnection();
                    // 设置相关参数
                    connection.setRequestMethod("GET");
                    connection.setConnectTimeout(8000);
                    connection.setReadTimeout(8000);
                    // 通过 connection 获取输入流
                    InputStream in = connection.getInputStream();
                    // 对输入流进行读取
                    reader = new BufferedReader(new InputStreamReader(in));
                    StringBuilder response = new StringBuilder();
                    String line;
                    while ((line = reader.readLine()) != null) {
                        response.append(line);
                    }
                    showResponse(response.toString());
                } catch (Exception e) {
                    e.printStackTrace();
                } finally {
                    // 关闭流
                    if (reader != null) {
                        try {
                            reader.close();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    }
                    // 关闭连接
                    if (connection != null) {
                        connection.disconnect();
                    }
                }

            }
        }).start();
    }

    /**
     * 通过 okHttp 访问网络
     */
    private void sendRequsetWithOkHttp() {
        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    OkHttpClient client = new OkHttpClient();
                    // 创建一个请求
                    Request request = new Request.Builder()
                            .url("http://www.baidu.com").build();
                    // 创建一个响应
                    Response response = client.newCall(request).execute();
                    String responseData = response.body().string();
                    showResponse(responseData);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }).start();
    }

    private void showResponse(final String response) {
        runOnUiThread(new Runnable() {
            @Override
            // 对 UI 进行操作，讲结果显示到页面上
            public void run() {
                responseText.setText(response);
            }
        });
    }
}
