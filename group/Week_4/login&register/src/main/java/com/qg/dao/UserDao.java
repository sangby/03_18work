package com.qg.dao;

import com.qg.po.User;

import java.sql.SQLException;

public interface UserDao {
    /**
     * 用用户名和密码查询用户
     *
     * @param userName 用户名
     * @param passWord 密码
     *
     * @return 用户
     */
    User selectByNameAndPassword(String userName,String passWord);


    /**
     * 按名称选择
     *
     * @param userName 用户名
     *
     * @return 用户
     */
    User selectByName(String userName);

    int insertNewOne(String userName,String password) throws SQLException;

}
