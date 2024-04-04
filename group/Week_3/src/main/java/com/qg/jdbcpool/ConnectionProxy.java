package com.qg.jdbcpool;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.sql.Connection;

public class ConnectionProxy implements InvocationHandler {
    //真正连接
    private Connection realConnection;
    //代理连接
    private Object proxyConnection;
    //持有数据源对象
    private MyDataSource myDataSource;

    public Connection getRealConnection() {
        return realConnection;
    }

    public void setRealConnection(Connection realConnection) {
        this.realConnection = realConnection;
    }

    public Object getProxyConnection() {
        return proxyConnection;
    }

    public void setProxyConnection(Connection proxyConnection) {
        this.proxyConnection = proxyConnection;
    }

    public ConnectionProxy(Connection realConnection, MyDataSource myDataSource) {
        this.realConnection = realConnection;
        this.myDataSource = myDataSource;

        //代理连接内部初始化
        this.proxyConnection = (Connection)Proxy.newProxyInstance(Connection.class.getClassLoader(),new Class<?>[]{Connection.class},this);
    }

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        return null;
    }
    //代理连接
}
