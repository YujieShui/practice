package com.shuiyujie.lbstest;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;
import android.widget.Toast;

import com.baidu.location.BDLocation;
import com.baidu.location.BDLocationListener;
import com.baidu.location.LocationClient;
import com.baidu.location.LocationClientOption;
import com.baidu.mapapi.SDKInitializer;
import com.baidu.mapapi.map.BaiduMap;
import com.baidu.mapapi.map.MapStatusUpdate;
import com.baidu.mapapi.map.MapStatusUpdateFactory;
import com.baidu.mapapi.map.MapView;
import com.baidu.mapapi.map.MyLocationData;
import com.baidu.mapapi.model.LatLng;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    public LocationClient mLocationClient;

    // 百度地图的总控制器
    // 对地图中的各项参数进行设置
    private BaiduMap baiduMap;

    private TextView positionText;

    private MapView mapView;

    private boolean isFirstLocate = true;

    public static final int UPDATE_TEXT = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        mLocationClient = new LocationClient(getApplicationContext());
        // 注册定位监听器，当获取位置信息时回调定位监听器
        mLocationClient.registerLocationListener(new MyLocationListenr());
        // 初始化操作，必须在 setContentView() 之前进行
        SDKInitializer.initialize(getApplicationContext());
        setContentView(R.layout.activity_main);
        positionText = (TextView) findViewById(R.id.position_text_view);
        mapView = (MapView) findViewById(R.id.bmapView);
        // 通过 mapView 的 getMap() 方法实例化 baiduMap
        baiduMap = mapView.getMap();
        // 允许出现定位的小光标
        baiduMap.setMyLocationEnabled(true);
        // 对多个权限进行判断，如果有响应权限则放到统一的权限列表中
        List<String> permissionList = new ArrayList<>();
        if (ContextCompat.checkSelfPermission(MainActivity.this, Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED) {
            permissionList.add(Manifest.permission.ACCESS_FINE_LOCATION);
        }
        if (ContextCompat.checkSelfPermission(MainActivity.this, Manifest.permission.READ_PHONE_STATE) != PackageManager.PERMISSION_GRANTED) {
            permissionList.add(Manifest.permission.READ_PHONE_STATE);
        }
        if (ContextCompat.checkSelfPermission(MainActivity.this, Manifest.permission.WRITE_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
            permissionList.add(Manifest.permission.WRITE_EXTERNAL_STORAGE);
        }
        if (!permissionList.isEmpty()) {
            String[] permissions = permissionList.toArray(new String[permissionList.size()]);
            // 一次性申请所有权限
            ActivityCompat.requestPermissions(MainActivity.this, permissions, 1);
        } else {
            requestLocation();
        }
    }

    private void requestLocation() {
        initLocation();
        mLocationClient.start();
    }

    /**
     * 用于刷新定位信息
     * 如果不刷新定位信息知会调用一次
     * 通过设置每隔 5 秒刷新定位信息实时获取定位
     */
    private void initLocation() {
        LocationClientOption option = new LocationClientOption();
        option.setScanSpan(5000);
        mLocationClient.setLocOption(option);
    }

    /**
     * 定位到自己所在的位置，以及设置缩放级别
     * isFirstLocate 防止多次调用
     * @param location
     */
    private void navigateTo(BDLocation location){
        if(isFirstLocate){
            LatLng ll = new LatLng(location.getLatitude(),location.getLongitude());
            MapStatusUpdate update = MapStatusUpdateFactory.newLatLng(ll);
            baiduMap.animateMapStatus(update);
            update = MapStatusUpdateFactory.zoomBy(16f);
            baiduMap.animateMapStatus(update);
            isFirstLocate = false;
        }
        // 用于获取定位的小光标
        MyLocationData.Builder locationBuilder = new MyLocationData.Builder();
        locationBuilder.latitude(location.getLatitude());
        locationBuilder.longitude(location.getLongitude());
        MyLocationData locationData = locationBuilder.build();
        baiduMap.setMyLocationData(locationData);
    }

    @Override
    protected void onResume() {
        super.onResume();
        mapView.onResume();
    }

    @Override
    protected void onPause() {
        super.onPause();
        mapView.onPause();
    }

    /**
     * 停止定位
     * 当活动销毁时需要停止定位，否则会在后台运行
     */
    @Override
    protected void onDestroy() {
        super.onDestroy();
        mLocationClient.stop();
        mapView.onDestroy();
        baiduMap.setMyLocationEnabled(false);
    }

    /**
     * 权限判断，所有权限都有才会调用 requestLocation() 启动定位
     *
     * @param requestCode
     * @param permissions
     * @param grantResults
     */
    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {

        switch (requestCode) {
            case 1:
                if (grantResults.length > 0) {
                    for (int result : grantResults) {
                        if (result != PackageManager.PERMISSION_GRANTED) {
                            Toast.makeText(this, "必须统一所有权限才能使用本程序", Toast.LENGTH_SHORT).show();
                            finish();
                            return;
                        }
                    }
                    requestLocation();
                } else {
                    Toast.makeText(this, "未知错误！", Toast.LENGTH_SHORT).show();
                    finish();
                }
                break;
            default:
        }
    }

    public class MyLocationListenr implements BDLocationListener {

        @Override
        public void onReceiveLocation(BDLocation bdLocation) {
            /**
             * 注释部分可用于获取定位信息
             */
//            final StringBuilder currentPosition = new StringBuilder();
//            currentPosition.append("经度：").append(bdLocation.getLatitude()).append("/n");
//            currentPosition.append("纬度：").append(bdLocation.getLongitude()).append("/n");
//            currentPosition.append("定位方式：");
//            if (bdLocation.getLocType() == BDLocation.TypeGpsLocation) {
//                currentPosition.append("GPS");
//            } else if (bdLocation.getLocType() == BDLocation.TypeNetWorkLocation) {
//                currentPosition.append("network");
//            }
//
////            runOnUiThread(new Runnable() {
////                @Override
////                public void run() {
////                    positionText.setText(currentPosition);
////                }
////            });
//
//            Message message = new Message();
//            message.what = UPDATE_TEXT;
//            Bundle bundle = new Bundle();
//            bundle.putString("currentPosition",currentPosition.toString());
//            message.setData(bundle);
//            handler.sendMessage(message);

            // 获取定位时，定位到自己所在的位置
            if(bdLocation.getLocType() == BDLocation.TypeGpsLocation || bdLocation.getLocType() == BDLocation.TypeNetWorkLocation){
                navigateTo(bdLocation);
            }
        }

        @Override
        public void onConnectHotSpotMessage(String s, int i) {

        }
    }

    private Handler handler = new Handler(){

        public void handleMessage(final Message msg){
            super.handleMessage(msg);

            switch (msg.what){
                case UPDATE_TEXT:
                    Bundle bundle = msg.getData();
                    String currentPosition = bundle.getString("currentPosition");
                    positionText.setText(currentPosition);
                    break;
                default:
            }
        }
    };

}
