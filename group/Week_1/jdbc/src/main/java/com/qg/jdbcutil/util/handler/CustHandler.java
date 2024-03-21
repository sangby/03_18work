package com.qg.jdbcutil.util.handler;

import com.qg.jdbcutil.entity.Customer;
import com.qg.jdbcutil.util.MyHandler;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

public class CustHandler implements MyHandler<List<Customer>> {

    @Override
    public List<Customer> handler(PreparedStatement ps) throws SQLException {
        Customer customer = null;
        //执行sql
        ResultSet rs = ps.executeQuery();
        //处理字符集,整合成一个对象
        if(rs.next()){

            String username = rs.getString("username");
            String password = rs.getString("password");
            customer = new Customer(username,password);
            return (List<Customer>) customer;
        }
        if(rs!=null) rs.close();
        return null;
    }
}
