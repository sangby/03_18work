package com.qg.service;

import com.qg.constant.Result;
import com.qg.po.User;

import java.sql.SQLException;

public interface UserService {


    /**
     * 登录
     *
     * @param username 用户名
     * @param password 密码
     */
    Result<User> login(String username, String password) throws SQLException;

    /**
     * 根据用户名查询用户
     *
     * @param userName 用户名
     *
     * @return 结果<用户>
     */
    Result<User> select(String userName);


    Result<User> register(String userName, String passWord) throws SQLException;
}
