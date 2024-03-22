package com.qg.jdbcutil.util;

import java.io.IOException;
import java.sql.*;
import java.util.Properties;

public class JDBCUtils {
    ///网址
    private static String url;
    //用户名
    private static String username;
//    密码
    private static String password;

    //静态区
    static {


        try {
            //获取资源文件配置
            Properties properties = new Properties();
            //从类路径中加载资源文件
            properties.load(JDBCUtils.class.getClassLoader().getResourceAsStream("db.properties"));
            url = properties.getProperty("url");
            username = properties.getProperty("username");
            password = properties.getProperty("password");
            //加载驱动
            Class.forName("com.mysql.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            //找不到驱动
            e.printStackTrace();
            System.out.println("找不到驱动");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
//Util内容====================================================================================================

    //获取一个数据库的连接对象Connection

    public static Connection getConnection() throws SQLException {
        return  DriverManager.getConnection(url, username, password);

    }

    //关闭所有资源
    public static void closeAll(Connection conn, PreparedStatement pstm, ResultSet rs) throws SQLException {
        if(conn!=null){
            conn.close();
        }
        if(pstm!=null){
            pstm.close();
        }
        if(rs!=null){
            rs.close();
        }
    }
//CRUD内容===================================================================================================

/*
* 通用的执行增删改的方法
*
* @param sql sql语句
* @param params 参数数组
* @return update 更新数据的条数
*
* */
//完成了获取连接和执行sql,参数是sql语句,和对象数组
    public static int Update(String sql, Object... params) throws SQLException {
        int update = 0;

        PreparedStatement ptmt = null;
        try {
            //获取连接,执行查询,设置占位符
            ptmt = getParams(sql, params);
            //返回更新数据条数
            update = ptmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        } finally {
            ptmt.close();
            return update;
        }


    }
    /*
     * 此方法获取了连接,预编译对象,并将参数填入了预编译对象
     *
     * @param sql sql语句
     * @param params 参数数组
     *@return 返回一个预编译声明
     *
     *
     *
     * */
    private static PreparedStatement getParams(String sql, Object... params) throws SQLException {
        //获取连接
        Connection conn = getConnection();
        //预编译声明
        PreparedStatement prepareStatement = conn.prepareStatement(sql);
        //逐个确认占位符的值
        for (int i = 0; i < params.length; i++) {
            //i+1 是参数的位置索引。在JDBC中，参数索引从1开始，而不是从0开始
            prepareStatement.setObject(i + 1, params[i]);
        }
        //释放资源
        conn.close();
        return prepareStatement;
    }

    /*
    * 通用的执行的查询的方法,这玩意是接口多态吗
    * @param handler 处理结果集
    * @param sql sql语句
    * @param params 参数数组
    * @param <T> 返回值类型
    * @return 返回特定的泛型
    * */
    public static <T> T query(String sql, MyHandler<T> handler, Object...params){
        //获取连接,获取预编译对象,确定占位符,执行sql语句,处理结果集,释放资源
        try{
            PreparedStatement ps = getParams(sql,params);
            return handler.handler(ps);
        }catch (SQLException e){
            e.printStackTrace();
            throw new RuntimeException(e);
        }
    }


    //测试方法
    public static void main(String[] args) throws SQLException {
        Connection connection = getConnection();
        System.out.println(connection);
    }
}
