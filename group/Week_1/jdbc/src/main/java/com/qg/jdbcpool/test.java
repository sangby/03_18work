package com.qg.jdbcpool;

import com.alibaba.druid.pool.DruidDataSource;
import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.IOException;
import java.util.Properties;

public class test {
    public static void main(String[] args) throws Exception {

//        试用一下druid
        Properties properties = null;
        try {
            properties = new Properties();
            properties.load(test.class.getClassLoader().getResourceAsStream("druid.properties"));
        } catch (IOException e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        }

        try {
            DataSource dataSource = DruidDataSourceFactory.createDataSource(properties);

            dataSource.getConnection().close();
        } catch (Exception e) {
            e.printStackTrace();
            throw new RuntimeException(e);
        }

        System.out.println("连接成功");

    }
}
