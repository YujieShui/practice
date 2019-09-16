package com.example.shui.game2048;

import android.app.Activity;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{

    public MainActivity() {
        mainActivity = this;
    }

    private int score = 0;
    private LinearLayout root; // 最外层容器
    private TextView tvScore; // 得分
    private TextView bestScore; // 最高分
    private Button newGameButton; // 新开局
    private GameView gameView; // 2048 矩阵
    private AnimLayer animLayer; // 未知

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        root = (LinearLayout) findViewById(R.id.container);
        root.setBackgroundColor(0xfffaf8ef);

        tvScore = (TextView) findViewById(R.id.tvScore);
        bestScore = (TextView) findViewById(R.id.tvBestScore);

        gameView = (GameView) findViewById(R.id.gameView);
        animLayer = (AnimLayer) findViewById(R.id.animLayer);

        newGameButton = (Button) findViewById(R.id.btnNewGame);
        newGameButton.setOnClickListener(this);
    }

    /**
     * 点击创建新的游戏
     * @param view
     */
    @Override
    public void onClick(View view) {
        gameView.startGmae();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // 填充菜单栏
        getMenuInflater().inflate(R.menu.main,menu);
        return super.onCreateOptionsMenu(menu);
    }

    /**
     * 技巧：方便获取 MainActivity
     */
    private static Activity mainActivity;

    public static Activity getMainActivity(){
        return mainActivity;
    }

}
