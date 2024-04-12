package com.qg.util.impl;


import com.qg.po.User;
import com.qg.util.MyHandler;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class UserHandler implements MyHandler<List<User>> {
    @Override
    public List<User> handler(PreparedStatement ps) throws SQLException {
        ResultSet rs = ps.executeQuery();
        List<User> list = new ArrayList<>();
        while(rs.next()){
            Integer id = rs.getInt("id");
            String username = rs.getString("username");
            String password = rs.getString("password");
            User user = new User(id,username,password);
            list.add(user);
        }
        return list;
    }
}
