package com.shuiyujie.calendarview;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.Toast;

import com.shuiyujie.calendarview.CalenderView.NewCalenderListener;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class MainActivity extends AppCompatActivity implements NewCalenderListener{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        CalenderView calenderView = (CalenderView) findViewById(R.id.calender_view);
        calenderView.listener = this;
    }


    @Override
    public void onItemLongPress(Date day) {
        DateFormat df = SimpleDateFormat.getInstance();
        Toast.makeText(this,df.format(day),Toast.LENGTH_SHORT).show();
    }
}
