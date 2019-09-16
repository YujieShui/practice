package com.shuiyujie.uilayouttest;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.List;

/**
 * Created by shui on 2017/7/26.
 */

public class FruitAdapter extends ArrayAdapter<Fruit> {

    private int resourceId;

    public FruitAdapter(Context context, int resource, List<Fruit> objects) {
        super(context, resource, objects);
        resourceId = resource;
    }

    @Override
    public View getView(int position,View convertView, ViewGroup parent) {
        Fruit fruit = getItem(position);
        View view = LayoutInflater.from(getContext()).inflate(resourceId, parent, false);
        ImageView fruitImg = (ImageView) view.findViewById(R.id.fruit_img);
        TextView fruitText = (TextView) view.findViewById(R.id.fruit_text);
        fruitImg.setImageResource(fruit.getFruitId());
        fruitText.setText(fruit.getName());
        return view;
    }
}
