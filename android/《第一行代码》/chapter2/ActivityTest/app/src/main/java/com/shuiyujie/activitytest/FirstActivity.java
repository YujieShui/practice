package com.shuiyujie.activitytest;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class FirstActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.first_layout);
        Button button1 = (Button) findViewById(R.id.button_1);
        button1.setOnClickListener(new View.OnClickListener(){

            // 使用Toast
            @Override
            public void onClick(View v) {
                //Toast.makeText(FirstActivity.this,"You Click Button_1",Toast.LENGTH_SHORT).show();
                // 显示调用 Intent
                Intent intent = new Intent(FirstActivity.this,SecondActivity.class);
                // 设置返回信息
                String data = "Hello SecondActivity";
                intent.putExtra("extra_data",data);
                // 隐式调用 Intent
                // Intent intent = new Intent("com.shuiyujie.activityTest.ACTION_START");
                // intent.addCategory("com.shuiyujie.activityTest.MY_CATEGORY");
                // startActivity(intent);
                // 获取下一个Activity的信息
                startActivityForResult(intent,1);
            }
        });

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main,menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()){
            case R.id.add_item:
                Toast.makeText(this,"You Click Add",Toast.LENGTH_SHORT).show();
                break;
            case  R.id.list_item:
                Toast.makeText(this,"You Click List",Toast.LENGTH_SHORT).show();
                break;
            default:

        }
        return true;
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {

        switch (requestCode){
            case 1: if(resultCode == RESULT_OK){
                String returnData = data.getStringExtra("extra_return");
                Log.d("FirstActivity",returnData);
                break;
            }
            default:
        }

    }
}
