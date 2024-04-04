package com.qg.jdbcpool.mypool;

import java.sql.Connection;
import java.sql.SQLException;

public interface pool {
    //获取连接池中的连接数量
     void getPoolNum();


     //=====以下方法很对称
    //创建连接池
     void createPool() throws SQLException;

    //从连接池中获取一个连接实例
    Connection getConnection() throws SQLException;
    //放回一个连接到连接池尾部,如果池中连接数达到poolMax则销毁
    void returnConnection(Connection conn) throws SQLException;
    //关闭连接池
    void closePool() throws SQLException;

}
