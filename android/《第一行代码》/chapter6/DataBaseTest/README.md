# SQLiteHelper 实现对 SQLite 数据库的操作

![SQLite](https://github.com/YujieShui/androidpratice/blob/master/chapter6/DataBaseTest/SQLite.png)

## 1. SQLite 数据库简介

安卓内置了 SQLite 数据库，他是一个轻量级的数据库应用程序，运行速度很快，占用资源很少。SQLite 数据库中的数据类型包括以下四种：integer 表示整型，real 表示浮点类型，text 表示文本类型，blob 表示二进制类型。

为了方便使用安卓提供了 SQLiteHelper 工具对数据库进行操作。本文记录 SQLiteHelper 的简单使用方式。

## 2. 创建数据库

```java
public class MyDataBaseHelper extends SQLiteOpenHelper {

    public static final String CREATE_BOOK = "create table book("
            + "id integer primary key autoincrement,"
            + "author text,"
            + "price real,"
            + "pages integer,"
            + "name text)";

    public static final String CREATE_CATEGORY = "create table Category ("
            + "id integer primary key autoincrement, "
            + "category_name text, "
            + "category_code integer)";

    private Context mContext;

    public MyDataBaseHelper(Context context, String name, SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
        mContext = context;
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(CREATE_BOOK);
        Toast.makeText(mContext, "创建数据库成功！", Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("drop table if exists Book");
        db.execSQL("drop table if exists Category");
        onCreate(db);
    }
}
```

自定义工具类继承 SQLiteOpenHelper，实现其中的两个方法 onCreate() 和 onUpgrade()，两者区别在于 onCreate() 用于数据库的创建，onUpgrade()用于数据库的更新。

使用 SQLiteOpenHelper 前需要调用 SQLiteOpenHelper 的构造方法传入四个参数，其中最后一个参数表示数据库的版本，当其版本号比前一个版本号大时执行更新操作。  

点击按钮创建数据库，为按钮注册点击事件：

```java
dbHelper = new MyDataBaseHelper(this,"BookStore.db",null,1);

        Button createButton = (Button) findViewById(R.id.create_dastabase);
        createButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                dbHelper.getWritableDatabase();
            }
        });
```

## 3. 添加数据

点击添加数据按钮添加数据，为按钮注册点击事件：

Button insertData = (Button) findViewById(R.id.insert_data);
        insertData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                SQLiteDatabase db = dbHelper.getWritableDatabase();
                ContentValues values = new ContentValues();
                // 开始组装第一条数据
                values.put("name", "The Da Vinci Code");
                values.put("author", "Dan Brown");
                values.put("pages", 454);
                values.put("price", 16.96);
                db.insert("Book", null, values); // 插入数据
                values.clear();
                // 开始组装第二条数据
                values.put("name", "The Lost Symbol");
                values.put("author", "Dan Brown");
                values.put("pages", 510);
                values.put("price", 19.95);
                db.insert("Book",null,values);// 插入数据
            }
        });

> db.insert("Book", null, values); // 插入数据

## 4. 修改数据

点击修改数据按钮添加数据，为按钮注册点击事件：

```java
Button updateData = (Button) findViewById(R.id.update_data);
        updateData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                SQLiteDatabase db = dbHelper.getWritableDatabase();
                ContentValues values = new ContentValues();
                values.put("price",100);
                db.update("book",values,"name = ?",new String[]{"The Da Vinci Code"});
            }
        });
```

> db.update("book",values,"name = ?",new String[]{"The Da Vinci Code"});

## 5. 删除数据

```java
Button deleteData = (Button) findViewById(R.id.delete_data);
        deleteData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                SQLiteDatabase db = dbHelper.getWritableDatabase();
                db.delete("book","page > ?",new String[]{"The Da Vinci Code"});
            }
        });
```

## 6. 查找数据

查询操作最复杂，这里使用最简单的查询所有并遍历输出：

```java
Button queryData = (Button) findViewById(R.id.query_data);
        queryData.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                SQLiteDatabase db = dbHelper.getWritableDatabase();
                // 查询Book表中所有的数据
                Cursor cursor = db.query("Book", null, null, null, null, null, null);
                if (cursor.moveToFirst()) {
                    do {
                        // 遍历Cursor对象，取出数据并打印
                        String name = cursor.getString(cursor.getColumnIndex("name"));
                        String author = cursor.getString(cursor.getColumnIndex("author"));
                        int pages = cursor.getInt(cursor.getColumnIndex("pages"));
                        double price = cursor.getDouble(cursor.getColumnIndex("price"));
                        Log.d("MainActivity", "book name is " + name);
                        Log.d("MainActivity", "book author is " + author);
                        Log.d("MainActivity", "book pages is " + pages);
                        Log.d("MainActivity", "book price is " + price);
                    } while (cursor.moveToNext());
                }
                cursor.close();
            }
        });
```
