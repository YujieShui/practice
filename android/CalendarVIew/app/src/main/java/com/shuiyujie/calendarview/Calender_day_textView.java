package com.shuiyujie.calendarview;


import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.support.annotation.Nullable;
import android.util.AttributeSet;
import android.widget.TextView;

/**
 * Created by shui on 2017/9/10.
 */

public class Calender_day_textView extends TextView{

    public boolean isToday = false; // 用于暴露方法

    private Paint paint = new Paint();

    public Calender_day_textView(Context context) {
        super(context);
    }

    public Calender_day_textView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
        initContol();
    }

    public Calender_day_textView(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        initContol();
    }

    /**
     * 初始化方法
     */
    private void initContol(){
        paint.setStyle(Paint.Style.STROKE);
        paint.setColor(Color.parseColor("#ff0000"));
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        if(isToday == true){
            canvas.translate(getWidth()/2,getHeight()/2);// 定位到中心点
            canvas.drawCircle(0,0,getWidth()/2,paint);
        }
    }
}
