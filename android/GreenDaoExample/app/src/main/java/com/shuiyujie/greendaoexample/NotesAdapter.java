package com.shuiyujie.greendaoexample;

import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by shui on 2017/8/24.
 */

public class NotesAdapter extends RecyclerView.Adapter<NotesAdapter.NotesViewHolder> {

    private NoteClickListener noteClickListener;

    private List<Note> datast;

    public interface NoteClickListener{
        void onNoteClick(int position);
    }

    static class NotesViewHolder extends RecyclerView.ViewHolder{

        public TextView text;
        public TextView comment;

        public NotesViewHolder(View itemView,final NoteClickListener noteClickListener) {
            super(itemView);

            text = (TextView) itemView.findViewById(R.id.textViewNoteText);
            comment = (TextView) itemView.findViewById(R.id.textViewNoteComment);

            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    if (noteClickListener != null){
                        noteClickListener.onNoteClick(getAdapterPosition());
                    }
                }
            });
        }
    }

    public NotesAdapter(NoteClickListener noteClickListener) {
        this.noteClickListener = noteClickListener;
        this.datast = new ArrayList<>();
    }

    //
    public void setNotes(List<Note> notes){
        datast = notes;
        notifyDataSetChanged();// ???????
    }

    // 获得指定位置的 note
    public Note getNote(int position){
        return datast.get(position);
    }

    @Override
    public NotesAdapter.NotesViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.item_note, parent, false);
        return new NotesViewHolder(view, noteClickListener);
    }

    @Override
    public void onBindViewHolder(NotesAdapter.NotesViewHolder holder, int position) {
        Note note = datast.get(position);
        holder.text.setText(note.getText());
        holder.comment.setText(note.getComment());
    }

    @Override
    public int getItemCount() {
        return datast.size();
    }
}
