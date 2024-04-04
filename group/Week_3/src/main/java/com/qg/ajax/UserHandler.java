package com.qg.ajax;


import com.qg.jdbcutil.util.MyHandler;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class UserHandler implements MyHandler <List<User>>{
    @Override
    public List<User> handler(PreparedStatement ps) throws SQLException {
        ResultSet rs = ps.executeQuery();
        List<User> list = new ArrayList<>();
        while(rs.next()){
            Integer id = rs.getInt("id");
            String name = rs.getString("name");
            String studentNumber = rs.getString("student_number");
            String phoneNumber = rs.getString("phone_number");
            String password = rs.getString("password");
            User user = new User(id,name,studentNumber,phoneNumber,password);
            list.add(user);
        }
        return list;
    }
}
