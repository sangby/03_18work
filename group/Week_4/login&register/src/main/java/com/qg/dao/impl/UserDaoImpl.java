package com.qg.dao.impl;

import com.alibaba.druid.util.JdbcUtils;
import com.qg.dao.UserDao;
import com.qg.po.User;
import com.qg.util.impl.PoolUtil;
import com.qg.util.impl.UserHandler;

import java.sql.SQLException;
import java.util.List;

public class UserDaoImpl implements UserDao {
    private UserDaoImpl() throws SQLException {
        PoolUtil.getPool();
    }
    @Override
    public User selectByNameAndPassword(String userName, String passWord) {
        String sql = "select * from `user` where `username`=? and`password`=?";
        try {
            List<User> list = PoolUtil.Tquery(sql, new UserHandler(), userName, passWord);
            if(list.isEmpty()){
                return null;
            }else{
                return list.get(0);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public User selectByName(String userName) {
        String sql = "select * from `user` where `userName`=?";
        try {
            return PoolUtil.Tquery(sql,new UserHandler(),userName).get(0);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public int insertNewOne(String userName, String password) throws SQLException {
        String sql = "insert into `user`(`username`,`password`) values(?,?)";
        return PoolUtil.update(sql,userName,password);
    }


}
