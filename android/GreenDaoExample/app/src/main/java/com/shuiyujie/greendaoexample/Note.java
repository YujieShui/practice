package com.shuiyujie.greendaoexample;

import org.greenrobot.greendao.annotation.Entity;
import org.greenrobot.greendao.annotation.Generated;
import org.greenrobot.greendao.annotation.Id;
import org.greenrobot.greendao.annotation.Index;
import org.greenrobot.greendao.annotation.NotNull;

import java.util.Date;

/**
 * Entity Note to create database
 * Created by shui on 2017/8/23.
 */
@Entity(indexes = {
        @Index(value = "text, date DESC", unique = true)
})
public class Note {

    @Id // 主键
    private Long id;

    private String comment;

    @NotNull // 不为空
    private String text;

    private Date date;

@Generated(hash = 1126070560)
public Note(Long id, String comment, @NotNull String text, Date date) {
    this.id = id;
    this.comment = comment;
    this.text = text;
    this.date = date;
}

@Generated(hash = 1272611929)
public Note() {
}

public Long getId() {
    return this.id;
}

public void setId(Long id) {
    this.id = id;
}

public String getComment() {
    return this.comment;
}

public void setComment(String comment) {
    this.comment = comment;
}

public String getText() {
    return this.text;
}

public void setText(String text) {
    this.text = text;
}

public Date getDate() {
    return this.date;
}

public void setDate(Date date) {
    this.date = date;
}
    
}
