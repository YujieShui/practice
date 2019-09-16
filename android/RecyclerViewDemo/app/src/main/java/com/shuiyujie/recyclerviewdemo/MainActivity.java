package com.shuiyujie.recyclerviewdemo;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private NormalAdapter normalAdapter;
    private List<String> notes;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        RecyclerView recyclerView = (RecyclerView) findViewById(R.id.recyclerViewNotes);
        normalAdapter = new NormalAdapter();
        recyclerView.setLayoutManager(new LinearLayoutManager(this));
        recyclerView.setAdapter(normalAdapter);
        this.setNotes();
    }

    private void setNotes(){
        notes = new ArrayList<>();
        notes.add("Java");
        notes.add("Android");
        notes.add("Gradle");
        notes.add("Kotlin");
        notes.add("Html");
        notes.add("Css");
        notes.add("JavaScript");
        notes.add("Docker");
        normalAdapter.setNote(notes);
    }


}
