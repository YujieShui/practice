package com.shuiyujie.forceoffline;

import android.content.Intent;
import android.content.SharedPreferences;
import android.preference.PreferenceManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;

public class LoginActivity extends AppCompatActivity {

    private SharedPreferences preferences;

    private SharedPreferences.Editor editor;

    private EditText accountEdit;

    private EditText passwordEdit;

    private Button loginButton;

    private CheckBox remberPassCheckBox;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_longin);
        preferences = PreferenceManager.getDefaultSharedPreferences(this);// 第一步：获取一个默认的 SharedPreferences 对象
        accountEdit = (EditText) findViewById(R.id.account);
        passwordEdit = (EditText) findViewById(R.id.password);
        loginButton = (Button) findViewById(R.id.login);
        remberPassCheckBox = (CheckBox) findViewById(R.id.rember_pass);

        // 第二步:判断 SharedPreferences 中是否存了 key 为 rember_password 的数据
        boolean isRember = preferences.getBoolean("rember_password", false);
        if (isRember) {
            // 将存储的账号密码设置文本框中
            String account = preferences.getString("account","");
            String password = preferences.getString("password","");
            accountEdit.setText(account);
            passwordEdit.setText(password);
            remberPassCheckBox.setChecked(true);
        }

        loginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String account = accountEdit.getText().toString();
                String password = passwordEdit.getText().toString();
                if (account.equals("admin") && password.equals("admin")) {
                    editor = preferences.edit();// 第三步：通过 preferences 获取editor对象
                    // 判断是否需要记住密码
                    if(remberPassCheckBox.isChecked()){
                        // 第四步：通过 editor 以键值对形式进行赋值
                        editor.putBoolean("rember_password",true);
                        editor.putString("password",password);
                        editor.putString("account",account);
                    } else {
                        editor.clear();
                    }
                    editor.apply(); // 最后一步：？
                    Intent intent = new Intent(LoginActivity.this, MainActivity.class);
                    startActivity(intent);
                    finish();
                } else {
                    Toast.makeText(LoginActivity.this, "账号或密码错误", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

}
