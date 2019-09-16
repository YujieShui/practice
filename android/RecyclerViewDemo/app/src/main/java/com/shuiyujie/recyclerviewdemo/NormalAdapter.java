package com.shuiyujie.recyclerviewdemo;

import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by shui on 2017/8/31.
 */

public class NormalAdapter extends RecyclerView.Adapter<NormalAdapter.NoteViewHolder> {

    private List<String> dataList = new ArrayList<>();

    static class NoteViewHolder extends RecyclerView.ViewHolder{

        public TextView text;

        public NoteViewHolder(View itemView) {
            super(itemView);
            text = itemView.findViewById(R.id.textViewNoteText);
        }
    }

    public NormalAdapter() {
        this.dataList = new ArrayList<>();
    }

    public void setNote(List<String> notes){
        dataList = notes;
        notifyDataSetChanged();
    }

    @Override
    public NoteViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = LayoutInflater.from((parent.getContext())).inflate(R.layout.item_note,parent,false);
        return new NoteViewHolder(view);
    }

    @Override
    public void onBindViewHolder(NoteViewHolder holder, int position) {
        holder.text.setText(dataList.get(position));
    }

    @Override
    public int getItemCount() {
        return dataList.size();
    }
}
