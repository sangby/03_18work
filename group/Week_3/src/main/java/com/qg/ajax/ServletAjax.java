package com.qg.ajax;

import com.alibaba.fastjson.JSON;
import com.qg.jdbcpool.mypool.PoolUtil;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

@WebServlet(name = "Servlet.Ajax", value = "/ajax")
public class ServletAjax extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        //接收数据
        String username = request.getParameter("username");
        if(username.equals("zhangsan")) System.out.println("咋没有输出的");
        else{
            System.out.println("啥意思");
        }

        User us = null;
        try {
            //查找
             us = this.getUser(username);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        //响应
        if(us== null){
            response.setStatus(400);
        }else{
            response.setStatus(200);
        }
        response.setContentType("application/json;charset=utf-8");
        response.getWriter().write(JSON.toJSONString(us));
    }

    /**
     * 通过用户名查找用户信息
     *
     * @param username 用户名
     *
     * @return 用户
     */
    User getUser(String username) throws SQLException {
        //初始化连接池
        PoolUtil.getPool();
        String sql = "select * from user where student_number = ?";
        Object[] obj = {username};
        List<User> tquery = PoolUtil.Tquery(sql, new UserHandler(), obj);
        return tquery.get(0);
    }
}


