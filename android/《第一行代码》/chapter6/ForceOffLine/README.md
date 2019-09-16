# 1. 安卓持久化

数据持久化就是将瞬时数据存储到存储设备中。安卓提供了三种方式存储数据：

1. 文件存储
2. SharedPreference存储
3. 数据库存储


# 2. SharedPreference存储

本文介绍使用 SharedPreference 存储，实现登录界面记住密码的功能。

SharedPreference 以键值对的形式存储数据，存进去的是字符串，取出来的任然是字符串；存进去的是布尔类型，取出来的也是布尔类型。所以根据存储类型的不同，提供了不同的获取值的方法。

## 2.1 SharedPreference 存储过程

**第一步**：获取 SharedPreference 对象：PreferenceManager.getDefaultSharedPreferences(this);

**第二步**：获取 SharedPreferences.Editor 对象，通过 SharedPreference .edit() 方法获取

**第三步**：通过 SharedPreferences.Editor 对象使用 putXXX() 向 SharedPreference 中添加 XXX 类型的数据

**第四步**：通过 apply() 方法提交数据，完成对数据存储的操作

## 2.2 代码实现记住密码功能

```java
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
                    editor.apply(); // 最后一步：提交数据
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
```

