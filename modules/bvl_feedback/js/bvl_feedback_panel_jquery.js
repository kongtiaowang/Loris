
/**
 * Created by evanmcilroy on 15-06-09.
 */
$(document).ready(function() {
// IBIS SPECIFIC OVERRIDE CODE IN IF CASE (ELSE CASE HAS THE DEFAULT LORIS CODE
    if (window.location.href.indexOf("instrument_list") > -1) {

        var candID = $('meta[itemprop="candID"]').attr("context");
        var sessionID = $('meta[itemprop="sessionID"]').attr("context");
        var commentID = $('meta[itemprop="commentID"]').attr("context");
        $("#bvl_feedback_menu").toggleClass("active_panel");
        $("#bvl_panel_wrapper").toggleClass("bvl_panel");
        $("#sidebar-wrapper").toggle("#sidebar-wrapper hide_sidebar");
        $("#page_wrapper_sidebar").toggleClass("wrapper");

        $('.navbar-toggle').on('click', function (event) {


            //We check if a sidebar exists on the page and toggle it if such.
            if ($("#page_wrapper_sidebar").length) {
                $("#sidebar-wrapper").toggle("#sidebar-wrapper hide_sidebar");
                $("#page_wrapper_sidebar").toggleClass("wrapper");
            }

        });
    }
//IBIS SPECIFIC OVERRIDE CODE ENDS HERE

    else{
        var candID = $('meta[itemprop="candID"]').attr("context");
        var sessionID = $('meta[itemprop="sessionID"]').attr("context");
        var commentID = $('meta[itemprop="commentID"]').attr("context");

        $('.navbar-toggle').on('click',function(event){
            $("#bvl_feedback_menu").toggleClass("active_panel");
            $("#bvl_panel_wrapper").toggleClass("bvl_panel");

            //We check if a sidebar exists on the page and toggle it if such.
            if ($("#page_wrapper_sidebar").length){
                $("#sidebar-wrapper").toggle("#sidebar-wrapper hide_sidebar");
                $("#page_wrapper_sidebar").toggleClass("wrapper");
            }

        });
    }

}); // end of document
