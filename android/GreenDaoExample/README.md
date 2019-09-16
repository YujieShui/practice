# 【安卓入门】GreenDao 的 Demo

初学安卓，在对 SQLite 数据库进行操作时，如果用安卓自带的 SQLiteHelper 不是很方便，效率也不高。所以了解到可以使用 ORM 框架，大名鼎鼎的是 GreenDao。

greenDao 是 Android 平台开源的对 SQLite 进行操作的 ORM 框架，通过让能够优雅快捷地对 SQLite 数据库进行操作。具体可以参考官网介绍，本次我就是通过官网教程照着做了一个 Demo:

> 官网地址：http://greenrobot.org/greendao/

# 第一步：添加相关依赖和插件

创建一个项目之后需要加入如下依赖：

### 1. app 目录下 build.gradle 中添加

```gradle
dependencies {
    ...
    compile 'org.greenrobot:greendao-generator:3.2.0'
    compile 'org.greenrobot:greendao:3.2.2' // add library
    ...
}
```

### 2. app 目录下 build.gradle 中直接添加

```gradle
apply plugin: 'com.android.application'
apply plugin: 'org.greenrobot.greendao' // apply plugin
```
### 3. 在根目录的 build.gradle 中添加

```gradle
dependencies {
        ...
    classpath 'org.greenrobot:greendao-gradle-plugin:3.2.2' // add plugin

    }
```
### 4. 跟着官网教程做报错
> Caused by: java.lang.ClassCastException: android.app.Application cannot be cast to com.shuiyujie.greendaoexample.App

app 目录下 build.gradle 中添加

```gradle
dependencies {
    ...
compile 'net.zetetic:android-database-sqlcipher:3.5.7@aar'
  ...
}
```

# 第二步：创建实体由 GreenDao 自动生成相应数据库

Note

```java
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
```

build -- make project 就会自动生成构造方法、Get/Set 方法和数据库。并且会在build/generated/source/greendao下生成 DAOMaster,DAOSession 以及 NoteDao。通过他们就能对数据库进行操作。

# 第三步: 获取 GrennDao 的 DaoSession

每一个DaoMaster持有一个数据库连接，通过 DaoMaste 可以获取 DaoSession。DaoSession 可以获取各实体类的对应DAO，然后相应的 Dao 就可以进行增删改查的操作了。

所以创建一个类用于获取 DaoSession

```java
public class App extends Application {

    public static final boolean ENCRYPTED = true;

    private DaoSession daoSession;

    @Override
    public void onCreate() {
        super.onCreate();
        DaoMaster.DevOpenHelper helper = new DaoMaster.DevOpenHelper(this, ENCRYPTED ? "notes-db-encrypted" : "notes-db");
        Database db = ENCRYPTED ? helper.getEncryptedWritableDb("super-secret") : helper.getWritableDb();
        daoSession = new DaoMaster(db).newSession();
    }

    public DaoSession getDaoSession() {
        return daoSession;
    }
}
```
# 第四步：通过 DaoSession 获取 NoteDao

要对 Note 的数据进行操作，要先获取 NoteDao。在 MainActivity 的 onCreate（）方法中获取。

```java

...
private NoteDao noteDao;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        this.setUpView();

        // 获取 note Dao
//        DaoSession daoSession = ((App) getApplication()).getDaoSession();
        DaoSession daoSession =  ((App)getApplication()).getDaoSession();
        noteDao = daoSession.getNoteDao();

      ...

    }
```

# 第五步：通过 NoteDao 操纵数据库

比如在 onCreate（）方法中获取 Note 的列表并通过 text 进行排序，列表显示 Note 只需要一句话:
```java
noteQuery=noteDao.queryBuilder().orderDesc(NoteDao.Properties.Text).build();
```

添加 Note:

``` java
Note note = new Note();
note.setText(noteText);
note.setComment(comment);
note.setDate(new Date());
noteDao.insert(note);
```

**更多可以参考：**
```
中文的详解：http://nightfarmer.github.io/2016/11/21/GreenDao3Doc/
官网的 API：http://greenrobot.org/files/greendao/javadoc/3.1/
Demo:https://github.com/YujieShui/androidpratice/tree/master/GreenDaoExample
```
