package com.shuiyujie.calendarview;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Color;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.GridView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;

/**
 * Created by shui on 2017/9/10.
 */

public class CalenderView extends LinearLayout {

    private ImageView btnPres;

    private ImageView btnNext;

    private TextView textDate;

    private GridView gridView;

    private Calendar curDate = Calendar.getInstance();

    private String disPlayFormat;

    public NewCalenderListener listener;

    public CalenderView(Context context) {
        super(context);
    }

    public CalenderView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
        init(context);

        TypedArray ta = getContext().obtainStyledAttributes(attrs,R.styleable.CalenderView);
        try {
            String format = ta.getString(R.styleable.CalenderView_dataFormat);
            disPlayFormat = format;
            if (disPlayFormat == null){
                disPlayFormat = "MMM YYY";
            }
        }finally {
            ta.recycle();
        }
        renderCalendar();
    }

    public CalenderView(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        init(context);
    }

    private void init(Context context) {
        bindControl(context);
        bindEvent(context);
    }

    /**
     * 绑定控件
     *
     * @param context
     */
    private void bindControl(Context context) {
        LayoutInflater inflater = LayoutInflater.from(context);
        inflater.inflate(R.layout.calender_view, this);

        btnPres = findViewById(R.id.btn_prev);
        btnNext = findViewById(R.id.btn_next);
        textDate = findViewById(R.id.calender_date);
        gridView = findViewById(R.id.calender_grid);
    }

    /**
     * 绑定事件
     *
     * @param context
     */
    private void bindEvent(Context context) {

        btnPres.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                curDate.add(Calendar.MONTH, -1);
                renderCalendar();
            }
        });

        btnNext.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {
                curDate.add(Calendar.MONTH, -1);
                renderCalendar();
            }
        });
    }

    /**
     * 渲染calender
     * 绘制日历
     */
    private void renderCalendar() {

        SimpleDateFormat sdf = new SimpleDateFormat(disPlayFormat);
        textDate.setText(sdf.format(curDate.getTime()));

        ArrayList<Date> cells = new ArrayList<>();
        Calendar calender = (Calendar) curDate.clone();

        calender.set(Calendar.DAY_OF_MONTH, 1);
        int prevDays = calender.get(Calendar.DAY_OF_WEEK) - 1;
        calender.add(Calendar.DAY_OF_MONTH, -prevDays);

        int maxCellCount = 6 * 7;
        while (cells.size() < maxCellCount) {
            cells.add(calender.getTime());
            calender.add(Calendar.DAY_OF_MONTH, 1);
        }

        gridView.setAdapter(new CalenderAdapter(getContext(),cells));
        gridView.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> parent, View view, int i, long l) {

                if (listener == null){
                    return false;
                }else {
                    listener.onItemLongPress((Date) parent.getItemAtPosition(i));
                    return true;
                }

            }
        });
    }

    private class CalenderAdapter extends ArrayAdapter<Date> {

        LayoutInflater inflater;

        public CalenderAdapter(@NonNull Context context,ArrayList<Date> days) {
            super(context, R.layout.calender_text_date,days);
            inflater = LayoutInflater.from(context);
        }

        @NonNull
        @Override
        public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {

            Date date = getItem(position);

            if (convertView == null){
                convertView = inflater.inflate(R.layout.calender_text_date,parent,false);
            }

            //自定义字体颜色

            ((TextView)convertView).setText(String.valueOf(date.getDate()));

            Date now = new Date();// 当前日期
            if(now.getMonth() == date.getMonth()){
                // 当月黑色
                ((TextView)convertView).setTextColor(Color.parseColor("#000000"));
            }else {
                // 不是当月灰色
                ((TextView)convertView).setTextColor(Color.parseColor("#666666"));
            }

            if(now.getDate() == date.getDate() && now.getMonth() == date.getMonth() && now.getYear() == now.getYear()){
                // 如果是当天设置成红色
                ((TextView)convertView).setTextColor(Color.parseColor("#ff0000"));
                ((Calender_day_textView)convertView).isToday = true;
            }

            // 自定义字体颜色结束

            return convertView;
        }
    }

    public interface NewCalenderListener{

        void onItemLongPress(Date day);
    }
}
