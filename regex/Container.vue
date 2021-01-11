<template>
  <div class="transition-container">
    <inc-transl
      :visible.sync="incTranslVisible"
      :save="incTranslSaveHandle"
      :append-to-body="true"
    >
    </inc-transl>

    <div class="HolyGrail mlang-mgt-container">
      <div class="HolyGrail-body">
        <main class="HolyGrail-content">
          <d-handle>
            <template slot="left">
              <el-button type="text" @click="incTransl">
                {{ $t('添加翻译') }}
              </el-button>
              <el-button type="text" @click="genTransl">
                {{ $t('生成翻译') }}
              </el-button>
              <el-button type="text" @click="genTranslApp">
                {{ $t('生成APP翻译') }}
              </el-button>
              <el-button type="text" @click="exp">
                {{ $t('common.export') }}
                <!-- 导出 -->
              </el-button>
              <el-button type="text" @click="imp">
                {{ $t('导入') }}
                <!-- 导出 -->
              </el-button>
<!--                 @input="setSearchKey($event)"
                @clear="
                  setSearchKey('');
                  getHolidaysList();
                "
                @keyup.enter.native="getHolidaysList" -->
              <el-input
                :placeholder="$t('请输入关键词搜索')"
                size="small"
                clearable
                style="width: 260px; margin-left: 20px"
                v-model="search_key"
              >
                <el-button
                  slot="append"
                  icon="el-icon-search"
                  @click="true"
                ></el-button>
              </el-input>
            </template>
          </d-handle>

          <el-table
            ref="contactTable"
            v-loading="mlangListLoading"
            :data="mlangList"
            tooltip-effect="dark"
            highlight-current-row
            @row-dblclick="mlangItemDbClick"
            :style="{ width: '100%' }"
            :height="screenHeight - 60 - 20 * 2 - 40 - 46 - 56"
            @selection-change="handleSelectionChange"
          >
            <template slot="empty">
              <d-table-empty></d-table-empty>
            </template>

            <!-- 多语言标记 -->
            <el-table-column
              prop="serv_name"
              :label="$t('多语言标记')"
              width="200"
            >
            </el-table-column>

            <!-- 所属页面 -->
            <el-table-column
              prop="patch_name"
              :label="$t('所属页面')"
              width="200"
            >
            </el-table-column>

            <!-- 多语言类型 -->
            <el-table-column
              prop="db_password"
              :label="$t('多语言类型')"
              width="100"
            >
            </el-table-column>

            <!-- 备注 -->
            <el-table-column prop="db_user" :label="$t('备注')">
            </el-table-column>

            <!-- 操作 -->
            <el-table-column :label="$t('操作')" width="180">
              <template slot-scope="scope">
                <el-button type="text" @click="editServer(scope.row)"
                  >{{ $t('编辑') }}
                  <!-- 编辑 --></el-button
                >
                <el-button type="text" @click="delServer(scope.row)"
                  >{{ $t('删除') }}
                  <!-- 删除 -->
                </el-button>
                <el-button type="text" @click="releaseServer(scope.row)"
                  >{{ $t('发布') }}
                  <!-- 发布 -->
                </el-button>
              </template>
            </el-table-column>
          </el-table>

          <div class="pagination-container">
            <el-pagination
              background
              @size-change="handleSizeChange"
              @current-change="handleCurrentChange"
              :current-page="current_page"
              :page-sizes="[20]"
              :page-size="page_size"
              layout="total, sizes, prev, pager, next, jumper"
              :total="total"
            ></el-pagination>
          </div>
        </main>
      </div>
    </div>
  </div>
</template>

<script>
import { mapState, mapActions, mapGetters, mapMutations } from "vuex";
import IncTransl from "@/pages/admin/components/langMgt/mLangMgt/IncTransl.vue";
import utils from "@/plugins/utils.js";

export default {
  components: {
    IncTransl,
  },
  computed: {
    ...mapState({
      screenWidth: (state) => state.screenWidth,
      screenHeight: (state) => state.screenHeight,
    }),
  },
  created() {},
  data() {
    return {
      mlangList: [],
      mlangListLoading: false,
      incTranslVisible: false,
      multipleSelection: [],
      search_key: ""
    };
  },
  methods: {
    incTranslSaveHandle(done) {
      done();
    },
    incTransl() {
      this.incTranslVisible = true;
    },
    genTransl() {
      debugger;
    },
    genTranslApp() {
      debugger;
    },
    exp() {
      debugger;
    },
    imp() {
      debugger;
    },
    handleSelectionChange(val) {
      this.multipleSelection = val;
    },
    editServer(row) {
      debugger;
    },
    delServer(row) {
      this.$api.mlangList
        .delPatchServer({
          mlang_id: row.mlang_id,
        })
        .then((response) => {
          if (response.data.success) {
            let d = response.data.data;
            this.loadmlangList();
          }
        })
        .catch((error) => {});
    },
    releaseServer(row) {
      debugger;
    },

    mlangItemDbClick(row, column, event) {
      debugger;
    },
    loadmlangList() {
      this.mlangListLoading = true;
      this.multipleSelection = [];

      // this.$api.mlangList
      //   .loadPatchServerList()
      //   .then((response) => {
      //     if (response.data.success) {
      //       let d = response.data.data;
      //       this.mlangList = d;

      //       this.mlangListLoading = false;
      //     }
      //   })
      //   .catch((error) => {
      //     this.mlangListLoading = false;
      //   });
    },
  },
};
</script>

<style lang="scss" scoped>
.mlang-mgt-container {
  .HolyGrail-content {
    border-right: $--border-base;
    border-bottom: $--border-base;
    margin-bottom: 19px;
  }
  .HolyGrail-nav,
  .HolyGrail-content {
    background-color: $--color-white;
  }
}
</style>

