package com.example.shui.game2048;

import android.content.Context;
import android.support.annotation.NonNull;
import android.view.Gravity;
import android.view.View;
import android.widget.FrameLayout;
import android.widget.TextView;

/**
 * Created by shui on 2017/8/15.
 */

public class Card extends FrameLayout {

    private TextView label;
    private View background;
    private int num = 0; // 默认初始值为0

    public Card(@NonNull Context context) {
        super(context);

        LayoutParams lp = null;

        background = new View(getContext());
        lp = new LayoutParams(-1, -1);
        lp.setMargins(10, 10, 0, 0);
        background.setBackgroundColor(0x33ffffff);
        addView(background, lp);

        label = new TextView(getContext());
        label.setTextSize(28);
        label.setGravity(Gravity.CENTER);

        lp = new LayoutParams(-1, -1);
        lp.setMargins(10, 10, 0, 0);
        addView(label, lp);

        setNum(0);
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;

        if (num <= 0) {
            label.setText("");
        } else {
            label.setText(num + "");
        }
        // 随着数字增大改变数字的颜色
        switch (num) {
            case 0:
                label.setBackgroundColor(0x00000000);
                break;
            case 2:
                label.setBackgroundColor(0xffeee4da);
                break;
            case 4:
                label.setBackgroundColor(0xffede0c8);
                break;
            case 8:
                label.setBackgroundColor(0xfff2b179);
                break;
            case 16:
                label.setBackgroundColor(0xfff59563);
                break;
            case 32:
                label.setBackgroundColor(0xfff67c5f);
                break;
            case 64:
                label.setBackgroundColor(0xfff65e3b);
                break;
            case 128:
                label.setBackgroundColor(0xffedcf72);
                break;
            case 256:
                label.setBackgroundColor(0xffedcc61);
                break;
            case 512:
                label.setBackgroundColor(0xffedc850);
                break;
            case 1024:
                label.setBackgroundColor(0xffedc53f);
                break;
            case 2048:
                label.setBackgroundColor(0xffedc22e);
                break;
            default:
                label.setBackgroundColor(0xff3c3a32);
                break;
        }
    }
}
