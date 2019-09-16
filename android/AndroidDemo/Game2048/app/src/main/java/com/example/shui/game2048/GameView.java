package com.example.shui.game2048;

import android.content.Context;
import android.widget.LinearLayout;

/**
 * Created by shui on 2017/8/14.
 */

public class GameView extends LinearLayout {

    public GameView(Context context) {
        super(context);
        initGameView();
    }


    /**
     * 开始新的游戏
     */
    public void startGmae() {
    }

    private void initGameView(){
        setOrientation(LinearLayout.VERTICAL);
        setBackgroundColor(0xffbbada0);


    }
}
